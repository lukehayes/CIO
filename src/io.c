#include "io.h"
#include <stdlib.h>

typedef struct BufferData
{
    char* data;
    size_t size;

} BufferData;

size_t IOGetFileSize(FILE* fp)
{
    fseek(fp, 0, SEEK_END);
    int file_length = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    return file_length;
}

const char* IOReadFile(const char* file)
{
    FILE* fp = fopen(file, "r+");

    int file_length = IOGetFileSize(fp);
    char* buffer = malloc(sizeof(char) * file_length + 1);

    if(ferror(fp))
        printf("An error occurred opening file %s \n", file);

    fread(buffer, 1, file_length,fp);

    fclose(fp);

    return buffer;
}

BufferData* IOReadFileIntoBuffer(const char* file)
{
    FILE* fp = fopen(file, "r+");

    int file_length = IOGetFileSize(fp);

    if(ferror(fp))
        printf("An error occurred opening file %s \n", file);

    BufferData* buffer = malloc(sizeof(BufferData));
    buffer->data = malloc(sizeof(char) * file_length);
    buffer->size = file_length;

    fread(buffer->data, 1, file_length,fp);

    fclose(fp);

    return buffer;
}

void IODestroyBufferData(BufferData* buffer)
{
    /*printf("Buffer of size: %li freed. \n", buffer->size);*/
    free(buffer->data);
    free(buffer);
}
