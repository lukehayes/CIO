#include "io.h"


size_t GetFileSize(FILE* fp)
{
    fseek(fp, 0, SEEK_END);
    int file_length = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    return file_length;
}

const char* ReadFile(const char* toml_file)
{
    FILE* fp = fopen(toml_file, "r+");

    int file_length = GetFileSize(fp);
    char* buffer = malloc(sizeof(char) * file_length + 1);

    if(ferror(fp))
        printf("An error occurred opening file %s \n", toml_file);

    fread(buffer, 1, file_length,fp);

    fclose(fp);

    return buffer;
}

BufferData* ReadFileIntoBuffer(const char* toml_file)
{
    FILE* fp = fopen(toml_file, "r+");

    int file_length = GetFileSize(fp);

    if(ferror(fp))
        printf("An error occurred opening file %s \n", toml_file);

    BufferData* buffer = malloc(sizeof(BufferData));
    buffer->data = malloc(sizeof(char) * file_length);
    buffer->size = file_length;

    fread(buffer->data, 1, file_length,fp);

    fclose(fp);

    return buffer;
}

void DestroyBufferData(BufferData* buffer)
{
    /*printf("Buffer of size: %li freed. \n", buffer->size);*/
    free(buffer->data);
    free(buffer);
}
