# Starting new project

ls -la -h | grep s - OK
ls -la -h | grep "s" | grep 'l' - OK
ls -la -h | grep "s" | grep 'l' | wc -l - OK


cat < README.md - OK
ls -la | grep l < README.md
ls -la | grep l | grep g < README.md
ls -la | grep l | grep g | grep a < README.md

ls > tmp.txt - OK

cat < RE>


ls | cat < README.md | grep "l" - OK

ls | cat < README.md | grep "l" > tmp.txt - BUG


