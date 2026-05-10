#!/bin/bash

# Configuration: Update this to your main folder
BASE_DIR="$HOME/Developer/Competitive Coding"

# Opens Neovim in the specified folder and automatically starts CompetiTest listening
function open_in_nvim() {
  local folder="$1"
  cd "$folder" || exit
  # This version schedules the command to run AFTER plugins are ready
  nvim -c "lua vim.schedule(function() vim.cmd('CompetiTest receive problem') end)"
}

# --- TUI Logic (Kept from your original script) ---
function select_option() {
    for i in $(seq 1 $#); do echo ""; done
    tput civis
    for i in $(seq 1 $#); do tput cuu1; done
    local selected=0
    while true; do
        for i in $(seq 0 $(($# - 1))); do
            local option
            eval "option=\${$((i + 1))}"
            if [ "$i" -eq "$selected" ]; then
                printf " \e[7m> %s. %s\e[0m\n" "$((i + 1))" "$option"
            else
                printf "    %s. %s\n" "$((i + 1))" "$option"
            fi
        done
        read -rsn1 key
        if [[ $key == "" ]]; then break; fi
        if [[ $key == $'\x1b' ]]; then read -rsn2 key; fi
        case $key in
        '[A') [ $selected -gt 0 ] && selected=$(($selected - 1)) ;;
        '[B') [ $selected -lt $(($# - 1)) ] && selected=$(($selected + 1)) ;;
        esac
        for i in $(seq 1 $#); do tput cuu1; done
    done
    tput cnorm
    eval "selected_option=\${$((selected + 1))}"
}

function handle_contest() {
    echo "Select a platform:"
    options=("Codeforces" "Code Chef" "AtCoder" "AZ" "Others")
    select_option "${options[@]}"
    platform=$selected_option

    [[ "$platform" == "Others" ]] && read -p "Enter platform name: " platform

    platformDir="$BASE_DIR/contests/$platform"
    mkdir -p "$platformDir"

    contest_options=("... Create new contest")
    if [ -d "$platformDir" ]; then
        dirs_sorted=$(find "$platformDir" -mindepth 1 -maxdepth 1 -type d -exec basename {} \; | sort)
        if [ -n "$dirs_sorted" ]; then
            while IFS= read -r line; do contest_options+=("$line"); done <<<"$dirs_sorted"
        fi
    fi

    echo "Select a contest:"
    select_option "${contest_options[@]}"
    selected_contest=$selected_option

    if [[ "$selected_contest" == "... Create new contest" ]]; then
        read -p "Enter contest name: " contestName
        sanitizedName=$(echo "$contestName" | tr -cd '[:alnum:]_ .()-' | cut -c1-100)
        contestDir="$platformDir/$sanitizedName"
        mkdir -p "$contestDir"
        open_in_nvim "$contestDir"
    else
        contestDir="$platformDir/$selected_contest"
        open_in_nvim "$contestDir"
    fi
}

function handle_practice() {
    practiceDir="$BASE_DIR/practice"
    mkdir -p "$practiceDir"
    open_in_nvim "$practiceDir"
}

# Main Execution
clear
echo "Select an option:"
main_options=("Contest" "Practice" "Exit")
select_option "${main_options[@]}"

case $selected_option in
"Contest") handle_contest ;;
"Practice") handle_practice ;;
"Exit") exit 0 ;;
esac
