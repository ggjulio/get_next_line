
(for ((i=0; i<20; i+=1)); do
	printf "||||||||||||||||||||||BUFFER_SIZE = %-5d  ||||||||||||||||||||||||||\n" $i
    gcc -g3 -Wall -Wextra -Werror -D BUFFER_SIZE=$i get_next_line.c main.c && ./a.out ~/documents/get_next_line/$1;
done
) | less