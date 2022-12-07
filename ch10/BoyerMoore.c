#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define ASCII_SET_CNT 256

int jumpMax(int jump1, int jump2) { return jump1 > jump2 ? jump1 : jump2; }

void BoyerMoore(char* str1, char* str2) {
	char nextSearch = 'y';
	int i, j, str1Len, str2Len, cnt = 0;
	int* jumpStep;

	str1Len = strlen(str1);
	str2Len = strlen(str2);

	jumpStep = (int*)calloc(ASCII_SET_CNT, sizeof(int));

	//점프 정보를 구함
	for (i = 0; i < ASCII_SET_CNT; i++) jumpStep[i] = str2Len;

	for (i = 0; i < str2Len; i++) jumpStep[(int)str2[i]] = str2Len - i - 1;

	printf("\n▷'%s'을(를) ", str2);

	i = 0;
	while (i <= str1Len - str2Len) {
		j = str2Len - 1;
		while (j >= 0 && str2[j] == str1[i + j]) j--;
		//찾게되면
		if (j < 0) {
			printf("\n▷%d 위치에서 찾음!\n", i);
			cnt++;
			printf("\n▶계속 찾을까요?(y/n): ");
			scanf_s("%c", &nextSearch, 1); getchar();
			i += str2Len;
		}
		else {
			//printf("\n→일치하지 않아 %d칸 이동함!", jumpMax((int)1, (int)jumpStep[(int)str1[i + j]] - (str2Len - j)));
			i += jumpMax((int)1, (int)jumpStep[(int)str1[i + j]] - (str2Len - j));
		}

		if (nextSearch != 'y' && nextSearch != 'Y')break;

	}

	printf("\n▷끝까지 %d회 찾았습니다.\n", cnt);

}

int main(void) {
	char* str1 = "【 a gift of unique beauty 】"\
		"\nI live with several chronic health conditions, including long-term survival of kidney and breast cancers."\
		"\nYet I remain an optimist who relishes the beauty of my life, even in its altered form."\
		"\nI don't have an easy answer for how I do this, but I do know that I am enrichedand sustained by my current relationshipsand the memories of earlier relationships that fill my heart with loveand hope."\
		"\nEvery Saturday evening when I was a child, we went to visit my cousins, bumping down the red dirt country road named after the money General Lee was said to have buried there."\
		"\nBeginning to smell Tante Lucille's biscuits even before the turn for her house, and eager to be huggedand kissed silly by her nine kids, my sisterand I chorused, \"Are we there yet?\""\
		"\nWe always ate crusty baguettes at home. But at Tante Lucille's, we were treated to hot, soft biscuits as big as platesand as light as cotton balls."\
		"\nWhen our stomachs were full of flaky biscuits drenched in freshly churned butter, we'd sit out back under the stars, drink sweet tea from Mason jars, and listen to Henriand Beau pick their guitarsand sing about love gone wrong."\
		"\nWe didn't know we were building memories. We were just kids passing time while Mamaand Tante Lucille visited."\
		"\n\nContinued...";
	char str2[50];

	printf("▼찾을 대상▼\n%s\n", str1);

	printf("\n▶찾을 문자열: ");
	gets_s(str2, 49);

	BoyerMoore(str1, str2);

	return 0;
}