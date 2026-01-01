#!/bin/bash

CP_PROFILE="CP"
BASE_DIR="$(pwd)"

# Opens the specified folder in VS Code using the "CP" profile.
function open_in_vscode() {
  local folder="$1"
  # macOS-specific command to open VS Code in a new window with a specific profile.
  code -n --profile "$CP_PROFILE" "$folder"
}

# Renders a TUI dropdown menu for selecting an option.
# This function is written to be compatible with older versions of bash.
#
# Usage: select_option "Option 1" "Option 2" "Option 3"
# The selected option is returned in the global variable `selected_option`.
function select_option() {
    # Clears the screen area for the menu to prevent flickering.
    for i in $(seq 1 $#); do
        echo ""
    done
    tput civis # Hide cursor
    for i in $(seq 1 $#); do
        tput cuu1
    done

    local selected=0
    while true; do
        # Loop through and display all options, highlighting the selected one.
        for i in $(seq 0 $(($# - 1))); do
            # Use `eval` to get the value of the Nth positional parameter ($1, $2, etc.)
            # This is a portable way to work around the lack of indirect expansion.
            local option
            eval "option=\${$((i+1))}"

            if [ "$i" -eq "$selected" ]; then
                printf " \e[7m> %s. %s\e[0m\n" "$((i+1))" "$option"
            else
                printf "   %s. %s\n" "$((i+1))" "$option"
            fi
        done

        # Read a single character of input.
        read -rsn1 key

        # On Enter, break the loop.
        if [[ $key == "" ]]; then
            break
        fi

        # Handle arrow keys (which are multi-character escape sequences).
        if [[ $key == $'\x1b' ]]; then
            read -rsn2 key
        fi

        case $key in
            '[A') # Up arrow
                if [ $selected -gt 0 ]; then
                    selected=$(($selected - 1))
                fi
                ;;
            '[B') # Down arrow
                if [ $selected -lt $(($# - 1)) ]; then
                    selected=$(($selected + 1))
                fi
                ;;
        esac

        # Move the cursor back to the top of the menu to redraw.
        for i in $(seq 1 $#); do
            tput cuu1
        done
    done
    tput cnorm # Show cursor again

    # Use `eval` to set the `selected_option` global variable.
    eval "selected_option=\${$((selected+1))}"
}

function handle_contest() {
  echo "Select a platform:"
  options=("Codeforces" "Code Chef" "AtCoder" "AZ" "Others")

  # Call the TUI selection function with the options.
  select_option "${options[@]}"
  platform=$selected_option

  # If "Others" was chosen, prompt for a custom name.
  if [[ "$platform" == "Others" ]]; then
    read -p "Enter platform name: " platform
  fi

  platformDir="$BASE_DIR/contests/$platform"
  mkdir -p "$platformDir"

  contest_options=("... Create new contest")
  if [ -d "$platformDir" ]; then
    # Read directories into the array, sorted
    dirs_sorted=$(find "$platformDir" -mindepth 1 -maxdepth 1 -type d -exec basename {} \; | sort)
    if [ -n "$dirs_sorted" ]; then
      while IFS= read -r line; do
          contest_options+=("$line")
      done <<< "$dirs_sorted"
    fi
  fi

  echo "Select a contest:"
  select_option "${contest_options[@]}"
  selected_contest=$selected_option

  if [[ "$selected_contest" == "... Create new contest" ]]; then
    read -p "Enter contest name: " contestName
    # Sanitize the name to create a valid directory name.
    sanitizedName=$(echo "$contestName" | tr -cd '[:alnum:]_-' | cut -c1-100)
    contestDir="$platformDir/$sanitizedName"
    mkdir -p "$contestDir"
    echo "Created contest directory: $contestDir"
    open_in_vscode "$contestDir"
  else
    contestDir="$platformDir/$selected_contest"
    echo "Opening contest directory: $contestDir"
    open_in_vscode "$contestDir"
  fi
}

function handle_practice() {
  practiceDir="$BASE_DIR/practice"
  mkdir -p "$practiceDir"
  echo "Opening practice directory."
  open_in_vscode "$practiceDir"
}

# Main script logic
echo "Select an option:"
main_options=("Contest" "Practice" "Exit")
select_option "${main_options[@]}"

case $selected_option in
  "Contest")
    handle_contest
    ;;
  "Practice")
    handle_practice
    ;;
  "Exit")
    exit 0
    ;;
esac