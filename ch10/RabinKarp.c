#include <stdio.h>
#include <string.h>
#include <math.h>

void RabinKarp(char* str1, char* str2) {
	char nextSearch = 'y';
	int i, j, str1Len, str2Len, cnt = 0;
	__int64 hashValue1 = 0, hashValue2 = 0;

	str1Len = strlen(str1);
	str2Len = strlen(str2);

	//해시값 계산에 사용되는 밑은 7로 정함.
	for (i = 0; i < str2Len; i++) hashValue2 += str2[i] * (int)pow((double)7, (double)(str2Len - i - 1));

	printf("\n▷'%s'을(를) ", str2);

	for (i = 0; i < str2Len; i++) hashValue1 += str1[i] * (int)pow((double)7, (double)(str2Len - i - 1));

	for (i = 0; i <= str1Len - str2Len; i++) {

		if (hashValue1 == hashValue2) {
			//찾을 문자열인지를 확인함.
			for (j = 0; j < str2Len; j++) if (str1[i + j] != str2[j])break;
			//찾게되면
			if (j == str2Len) {
				printf("\n▷%d 위치에서 찾음!\n", i);
				cnt++;
				printf("\n▶계속 찾을까요?(y/n): ");
				scanf_s("%c", &nextSearch, 1); getchar();
			}
		}

		if (nextSearch != 'y' && nextSearch != 'Y')break;

		//한 칸 오른쪽으로 이동하여 해시값 계산
		hashValue1 = 7 * (hashValue1 - str1[i] * (int)pow((double)7, (double)(str2Len - 1))) + str1[i + str2Len];
	}

	printf("\n▷끝까지 %d회 찾았습니다.\n", cnt);

}

int main(void) {
	char* str1 = "[A Gift of Unique Beauty]"\
		"\nI live with several chronic health conditions, including long-term survival of kidney and breast cancers."\
		"\nYet I remain an optimist who relishes the beauty of my life, even in its altered form."\
		"\nI don't have an easy answer for how I do this, but I do know that I am enrichedand sustained by my current relationshipsand the memories of earlier relationships that fill my heart with loveand hope."\
		"\nEvery Saturday evening when I was a child, we went to visit my cousins, bumping down the red dirt country road named after the money General Lee was said to have buried there."\
		"\nBeginning to smell Tante Lucille's biscuits even before the turn for her house, and eager to be huggedand kissed silly by her nine kids, my sisterand I chorused, \"Are we there yet?\""\
		"\nWe always ate crusty baguettes at home. But at Tante Lucille's, we were treated to hot, soft biscuits as big as platesand as light as cotton balls."\
		"\nWhen our stomachs were full of flaky biscuits drenched in freshly churned butter, we'd sit out back under the stars, drink sweet tea from Mason jars, and listen to Henriand Beau pick their guitarsand sing about love gone wrong."\
		"\nWe didn't know we were building memories. We were just kids passing time while Mamaand Tante Lucille visited.";
	char str2[50];

	printf("▼찾을 대상▼\n%s\n", str1);

	printf("\n▶찾을 문자열[대소문자 구분]: ");
	gets_s(str2, 49);

	RabinKarp(str1, str2);

	return 0;
}