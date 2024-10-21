//原版
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define MAX_LINE_LENGTH 2048 // 定义每行最大字符数 
#define START_COLUMN 9 // J列为第9列 (从0开始)36//41 
#define END_COLUMN 104 
#define START_ROW 2 // 从第2行开始 
#define END_ROW 43 // 到第30行结束 //33//29

int main()
{
    FILE* inputFile, * outputFile;
    char line[MAX_LINE_LENGTH];

    inputFile = fopen("input.csv", "r");
    if (inputFile == NULL)
    {
        perror("Error opening input file");
        return EXIT_FAILURE;
    } // 打开输出的csv文件 

    outputFile = fopen("output.csv", "w");

    if (outputFile == NULL)
    {
        perror("Error opening output file");
        fclose(inputFile);
        return EXIT_FAILURE;
    }
    int currentRow = 0; // 逐行读取输入文件 
    while (fgets(line, sizeof(line), inputFile) != NULL)
    {
        currentRow++; // 仅处理第2行到第30行 
        if (currentRow >= START_ROW && currentRow <= END_ROW)
        {
            char* token;
            int currentColumn = 0; // 分割每一行的数据 
            token = strtok(line, ",");
            while (token != NULL)
            {
                currentColumn++; // 仅处理从第J列到第DA列的列数据 
                if (currentColumn >= START_COLUMN && currentColumn <= END_COLUMN)
                { 
                    fprintf(outputFile, "%s\n", token);
                    
                } // 读取下一列 
                token = strtok(NULL, ",");
            }
        }
    }

    // 关闭文件 
    fclose(inputFile);
    fclose(outputFile);
    printf("Data has been successfully written to output.csv\n");
    return EXIT_SUCCESS;
}
