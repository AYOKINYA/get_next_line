# get_next_line
get_next_line reads from its first argument with a buffer size given when compiled,
and feeds a line seperated by "\n" to its second argument.
gnl returns 0, 1 or -1.
Return values indicate
0 : get_next_line reached EOF (End Of File).
1 : get_next_line sucessfully read a line (without "\n").
-1 : An error has occured during execution.

a simple main for get_next_line from STDIN :

int	main(void)
{
	char *line;

	line = 0;
	while (get_next_line(0, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	return (0);
}

I revised get_next_line.c and get_next_line_utils.c after exam rank 02.
My gnl wasn't able to read a big-fat line (which is "test" included in this repository).
seolim @42seoul diagnosed my gnl might consume too much memory when malloc so that fd keeps closing and opening. 
Thanks to seolim!
I removed ft_memmove and simply replaced it with free & ft_strdup.
I used ft_substr instead of declaring a tmp char array and copying some part of buf into the tmp array.
It's easier to understand how gnl goes in the new version!
I left gnl_bonus file as it is to compare the difference between the old ver. and the new ver.
