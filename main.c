#include <stdint.h>
#include <stdio.h>
#include <time.h>

uint32_t x = 0, w = 0, s = 0xb5ad4eceda1ce2a9;

inline static uint32_t msws() {

	x = (uint32_t)(time(NULL));

	x *= x;
	x += (w += s);
	x = (x >> 32) | (x << 32);
	return x;

}

int main()
{

	FILE *fp, *fs;

	fp = fopen("public_random.txt", "w");
	fs = fopen("private_random.txt", "w");

	int min, max, nr;

	printf("Enter the minimal value");
	scanf("%d", &min);
	printf("Enter the maximal value");
	scanf("%d", &max);

	for (int i = 0; i < 101; i++)
	{
		if (i == 100)
			fprintf(fs, "%d ", msws() % max + min);
		else
			fprintf(fp, "%d ", msws() % max + min);
	}

	fclose(fs);
	fclose(fp);

	return 0;
}