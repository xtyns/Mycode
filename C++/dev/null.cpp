#include <stdio.h>
#include <string.h>

int main() {
	int n;
	scanf("%d", &n);
	getchar(); // ¶ÁÈ¡»»ÐÐ·û

	for (int i = 0; i < n; i++) {
		char s[100];
		fgets(s, sizeof(s), stdin);
		s[strcspn(s, "\n")] = '\0'; // È¥³ý»»ÐÐ·û

		char *first = strtok(s, ", ");
		char *second = strtok(NULL, ", ");

		// ÅÐ¶ÏÊÇ·ñÑ¹¡°ong¡±ÔÏ
		char *lastWordFirst = strrchr(first, ' ');
		char *lastWordSecond = strrchr(second, ' ');
		if (strcmp(lastWordFirst + 1, "ong") == 0 && strcmp(lastWordSecond + 1, "ong.") == 0) {
			strcpy(lastWordSecond + 1, "qiao ben zhong.");
			printf("%s, %s\n", first, second);
		} else {
			printf("Skipped\n");
		}
	}

	return 0;
}