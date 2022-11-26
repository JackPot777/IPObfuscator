// See LICENSE file for copyright and license details.
//
// Danger! Danger! Danger!
// Crappy code here!
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void
usage(char *program_name)
{
	printf("Usage: %s <ip> [prefix] [postfix]\n", program_name);
	exit(0);
}

void
die(char *msg)
{
	fprintf(stderr, "[!] Error: %s!\n", msg);
	exit(-1);
}

void
banner()
{
	const static char *banner =
	" ---------------------------------------------------------------------\n"
	"                 Welcome to IPObfuscator                              \n"
	"                                                                      \n"
	"  Coded by       @OsandaMalith  (http://osandamalith.wordpress.com)   \n"
	"                 @1lastBr3ath   (http://cm2.pw)                       \n"
	"  Remastered by  @chinarulezzz  (https://github.com/chinarulezzz)     \n"
	" ---------------------------------------------------------------------\n";

	printf(banner);
}

_Bool
valid(char *ip)
{
	int segs = 0, chcnt = 0, accum = 0;

	while (*ip)
	{
		if (*ip == '.')
		{
			if (!chcnt)
				return 0;

			if (++segs == 4)
				return 0;

			chcnt = accum = 0;
			ip++;
			continue;
		}

		if ((*ip < '0') || (*ip > '9'))
			return 0;

		if ((accum = accum * 10 + *ip - '0') > 255)
			return 0;

		chcnt++;
		ip++;
	}

	if (segs != 3)
		return 0;

	if (!chcnt)
		return 0;

	return 1;
}

int
main(int argc, char **argv)
{
	if (argc < 2
	||  strcmp(argv[1], "-h")      == 0
	||  strcmp(argv[1], "--help")  == 0
	) {
		banner();
		usage(argv[0]);
	}

	char ip[100]      = {0},
	     prefix[100]  = {0},
	     postfix[100] = {0};
	char *token;
	unsigned int dword, dec[3];

	strncpy(ip, argv[1], 100);

	if (argc >= 3)
		strncpy(prefix,  argv[2], 100);
	if (argc == 4)
		strncpy(postfix, argv[3], 100);

	if (! valid(ip))
		die("invalid IP address");

	token = strtok(ip, ".");
	
	for (size_t i = 0; token; i++) {
		*(dec+i) = atoi(token);
		token = strtok(NULL, ".");
	}


#define pprefix  { if (prefix)  printf("%s",   prefix); }
#define ppostfix { if (postfix) printf("%s\n", postfix); else printf("\n"); }

	pprefix;
	printf("%u", dword=(*dec << 24)|(*(dec+1) << 16)|(*(dec+2) << 8)|*(dec+3));
	ppostfix;

	pprefix; printf("0x%X",dword); ppostfix;
	pprefix; printf("0%o",dword);  ppostfix;

	pprefix;
	for (size_t i = 0; i < 4; i++)
		printf( i == 3 ? "0x%02X" : "0x%02X.", dec[i]);
	ppostfix;

	pprefix;
	for (size_t i = 0; i < 4; i++)
		printf( i == 3 ? "%04o" : "%04o.", dec[i]);
	ppostfix;

	pprefix;
	for (size_t i = 0; i < 4; i++)
		printf( i == 3 ? "0x%010X" : "0x%010X.", dec[i]);
	ppostfix;

	pprefix;
	for (size_t i = 0; i < 4; i++)
		printf( i == 3 ? "%010o" : "%010o.", dec[i]);
	ppostfix;

	pprefix;
	for (size_t i = 0; i < 4; i++)
		printf( i == 3 ? "%i" :"0x%02X.", dec[i]);
	ppostfix;

	pprefix;
	for (size_t i = 0; i < 4; i++)
		printf( i >= 2 ? i == 3 ? "%i" : "%i." : "0x%02X.", dec[i]);
	ppostfix;

	pprefix;
	for (size_t i = 0; i < 4; i++)
		printf( i >= 1 ? i == 3 ? "%i" : "%i." : "0x%02X.", dec[i]);
	ppostfix;

	pprefix;
	for (size_t i = 0; i < 4; i++)
		printf( i == 3 ? "%i" :"%04o.", dec[i]);
	ppostfix;

	pprefix;
	for (size_t i = 0; i < 4; i++)
		printf( i >= 2 ? i == 3 ? "%i" : "%i." : "%04o.", dec[i]);
	ppostfix;

	pprefix;
	for (size_t i = 0; i < 4; i++)
		printf( i >= 1 ? i == 3 ? "%i" : "%i." : "%04o.", dec[i]);
	ppostfix;

	pprefix;
	for (size_t i = 0; i < 4; i++)
		if (i < 2) printf("0x%02X.", dec[i]);
	printf("%u", (*(dec+2) << 8)|*(dec+3));
	ppostfix;

	pprefix;
	for (size_t i = 0; i < 4; i++)
		if (i < 2) printf("%04o.", dec[i]);
	printf("%u", (*(dec+2) << 8)|*(dec+3));
	ppostfix;

	pprefix;
	for (size_t i = 0; i <2;i++)
		printf( i >= 1 ? "%04o." : "0x%02X.", dec[i]);
	printf("%u", (*(dec+2) << 8)|*(dec+3));
	ppostfix;

	pprefix;
	for (size_t i = 0; i < 4; i++)
		if (i < 1) printf("0x%02X.", dec[i]);
	printf("%u", (*(dec+1) << 16)|(*(dec+2) << 8)|*(dec+3));
	ppostfix;

	pprefix;
	for (size_t i = 0; i < 4; i++)
		if (i < 1) printf("%04o.", dec[i]);
	printf("%u", (*(dec+1) << 16)|(*(dec+2) << 8)|*(dec+3));
	ppostfix;

	pprefix;
	for (size_t i = 0; i < 4; i++)
		printf( i >= 2 ? i == 3 ? "%04o" : "%04o." : "0x%02X.", dec[i]);
	ppostfix;

	pprefix;
	for (size_t i = 0; i < 4; i++)
		printf( i >= 1 ? i == 3 ? "%04o" : "%04o." : "0x%02X.", dec[i]);
	ppostfix;

	pprefix;
	for (size_t i = 0; i <2;i++)
		printf( i >= 1 ? "%04o." : "0x%02X.", dec[i]);
	printf("%u", (*(dec+2) << 8)|*(dec+3));
	ppostfix;

#ifndef __unix__
	system("pause > nul");
#endif
	return 0;
}

// vim:sw=2:ts=2:sts=2:noet:cc=80
// End of file
