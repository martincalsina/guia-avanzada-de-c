//dummy impls de los types
#include "type.h"

fat32_t* new_fat32() {
    fat32_t* v = malloc(sizeof(fat32_t));
    *v = 1;
    return v;
}

ext4_t* new_ext4() {
    ext4_t* v = malloc(sizeof(ext4_t));
    *v = 2;
    return v;
}

ntfs_t* new_ntfs() {
    ntfs_t* v = malloc(sizeof(ntfs_t));
    *v = 3;
    return v;
}

fat32_t* copy_fat32(fat32_t* file) {
    fat32_t* p = malloc(sizeof(fat32_t));
    *p = *file;
    return p;

}

ext4_t* copy_ext4(ext4_t* file) {
    ext4_t* p = malloc(sizeof(ext4_t));
    *p = *file;
    return p;

}

ntfs_t* copy_ntfs(ntfs_t* file) {
    ntfs_t* p = malloc(sizeof(ntfs_t));
    *p = *file;
    return p;

}

void rm_fat32(fat32_t* file) {
    free(file);
}
void rm_ext4(ext4_t* file) {
    free(file);
}
void rm_ntfs(ntfs_t* file) {
    free(file);
}