/*
 * File: vfs_main.c
 * Author: Fabien Siron <fabien.siron@epita.fr>
 */

#include <kernel/pyr0.h>
#include <kernel/vfs.h>

#include <string.h>

static struct inode inode_array[INODE_ARRAY_LEN];
static struct filedesc fds;
static struct vfs vfs;

# define MAX_FS     7

struct fs_vector {
	u8 size;
	struct fs fs[MAX_FS];
} fs_vector = {
	.size = 0,
};

int register_fs(struct fs *fs) {
	if (fs_vector.size == MAX_FS)
		return -1;

	memcpy(&fs_vector.fs[fs_vector.size], fs, sizeof(struct fs));
	fs_vector.size++;

	return 0;
}

void vfs_init(void) {
	/* instal fds */
	int i;
	for (i = 0; i < FD_MAX; i++) {
		fds.files[i] = NULL;
	}
	memset(&vfs.root, 0, sizeof(vfs.root));
	memset(&vfs.pwd, 0, sizeof(vfs.pwd));
}
