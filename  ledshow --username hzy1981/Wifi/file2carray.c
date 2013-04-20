/*
   create by qinglong1983@gmail.com
 */
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
// covert 

#define LINE_MAX 60
int ftoc ( char * p_read_file, char * p_write_file )
{
	char buffer[64] = {0};

	FILE *h_read     = NULL;
	FILE *h_write    = NULL;
	int read_count  = 0;
	int write_count = 0;	
	int line_max = 0;
	unsigned char byte;
	h_read = fopen( p_read_file, "rb" );
	if ( h_read == NULL )
	{
		return 0;
	}
	h_write = fopen( p_write_file, "w" );
	if ( h_write == NULL )
	{
		fclose( h_read );
		return 0;
	}

#if 0
	fwrite(html,sizeof(char),sizeof(html),h_write);
	fclose(h_read);
        fclose(h_write);
        return 1;
#endif

	fwrite( "#ifndef __HTML__ \n #define __HTML__ \nconst unsigned char html[] = {\n", 1, strlen("#ifndef __HTML__ \n #define __HTML__ \nconst unsigned char html[] = {\n"), h_write );

	do
	{
		byte = 0;
		memset( buffer, 0, 64 );
		read_count = fread(&byte, 1, 1, h_read);
		if ( read_count == 1 )
		{
			sprintf(buffer , "0x%02x,", byte );
			printf(buffer , "0x%02x,", byte );
			write_count = fwrite( buffer, 1, strlen(buffer), h_write );
#if 1

			if ( line_max >= (LINE_MAX-1) )
			{
				line_max = 0;
				printf("\n");
				write_count = fwrite( "\r\n", 1, strlen("\r\n"), h_write );
			}
			else
			{
				line_max++;
			}
#endif
		}

	}while ( read_count == 1 );

	fwrite( "\n};\n#endif\n", 1, strlen("\n};\n#endif\n"), h_write );
	fclose(h_read);
	fclose(h_write);
	return 1;
}

int main(int argc, char* argv[])
{
	if ( argc < 3 )
	{
		printf("usage: ftoc file1 file2 ");
		return 0;
	}

	ftoc( argv[1], argv[2] );

	return 0;
}


