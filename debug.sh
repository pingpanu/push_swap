# debug.sh
#!/bin/bash
#echo "size = $1"
ARG=$(ruby -e "puts (1..$1).to_a.shuffle.join(' ')")
echo "ARG = $ARG"
valgrind -q --leak-check=full ./push_swap $ARG
echo "times =  $(./push_swap $ARG | wc -l)"