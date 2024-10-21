//ԭ��
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define MAX_LINE_LENGTH 2048 // ����ÿ������ַ��� 
#define START_COLUMN 9 // J��Ϊ��9�� (��0��ʼ)36//41 
#define END_COLUMN 104 
#define START_ROW 2 // �ӵ�2�п�ʼ 
#define END_ROW 43 // ����30�н��� //33//29

int main()
{
    FILE* inputFile, * outputFile;
    char line[MAX_LINE_LENGTH];

    inputFile = fopen("input.csv", "r");
    if (inputFile == NULL)
    {
        perror("Error opening input file");
        return EXIT_FAILURE;
    } // �������csv�ļ� 

    outputFile = fopen("output.csv", "w");

    if (outputFile == NULL)
    {
        perror("Error opening output file");
        fclose(inputFile);
        return EXIT_FAILURE;
    }
    int currentRow = 0; // ���ж�ȡ�����ļ� 
    while (fgets(line, sizeof(line), inputFile) != NULL)
    {
        currentRow++; // �������2�е���30�� 
        if (currentRow >= START_ROW && currentRow <= END_ROW)
        {
            char* token;
            int currentColumn = 0; // �ָ�ÿһ�е����� 
            token = strtok(line, ",");
            while (token != NULL)
            {
                currentColumn++; // ������ӵ�J�е���DA�е������� 
                if (currentColumn >= START_COLUMN && currentColumn <= END_COLUMN)
                { 
                    fprintf(outputFile, "%s\n", token);
                    
                } // ��ȡ��һ�� 
                token = strtok(NULL, ",");
            }
        }
    }

    // �ر��ļ� 
    fclose(inputFile);
    fclose(outputFile);
    printf("Data has been successfully written to output.csv\n");
    return EXIT_SUCCESS;
}
