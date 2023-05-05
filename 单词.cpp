#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

int main() {

	int paragraphs = 0, words = 0;       //paragraphs ��ʾ��������words��ʾĳһ�εĵ�����

	int min = 65525, ave = 0, max = 0, sum = 0;  //min��ʾ��С����ĵ�������max��������ĵ�������sum����������
	FILE *fp;        //�ļ�ָ��
	char buffer[MAX_LINE];        //������
	int len ;    //���ַ�����
	int i;
	fp = fopen("test.txt", "r");
	if (fp == NULL) {
		printf("cannot open file!");
		exit(0);
	}
	//��ȡ�ļ�����
	while (! feof(fp)) {
		// fgets() �ڶ��� MAX_LINE ���ַ�֮ǰ������ ���з� �� EOF ���������
		if (fgets(buffer, MAX_LINE, fp) != NULL) {
			paragraphs ++;
			len = strlen(buffer);
			//������һ���ո�֮ǰ����һ������
			words = 1;
			sum ++;
			//len - 1 ��Ϊ��ȥ�����з���ռλ��
			for (i = 0; i < len - 1; i++) {
				if (buffer[i] == ' ') {
					words ++;
					sum ++;
				}
			}
		}
		if (min > words) {
			min = words;
		}
		if (max < words) {
			max = words;
		}
	}
	fclose(fp);
	ave = sum / paragraphs;
	printf(" �ܵ�����Ϊ %d \n \n", sum);
	printf(" ��С���䵥����Ϊ %d \n \n", min);
	printf(" �����䵥����Ϊ %d \n \n", max);
	printf(" �ܶ�����Ϊ %d \n \n", paragraphs);
	printf(" ����ƽ��������Ϊ %d \n", ave);
}
