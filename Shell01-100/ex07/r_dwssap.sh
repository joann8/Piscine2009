cat /etc/passwd | grep -vE ^# | sed -n 'n;p' | awk -F: '{print $1}' | rev | sort -r | awk "NR >= $FT_LINE1 && NR <= $FT_LINE2" | xargs | sed 's/ /, /g' | tr "\n" "."
