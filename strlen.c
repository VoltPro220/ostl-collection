

const int strlen_c(const char* str)
{
	int count = 0;

	for(; str[count] != '\0'; count++);

	return count;
}

