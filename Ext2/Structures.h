

typedef  _int16 Int16;
typedef  _int32 Int32;

typedef unsigned _int16 UInt16;
typedef unsigned _int32 UInt32;
 
typedef struct
{
	UInt32   s_inodes_count;         /* Inodes count */
	UInt32   s_blocks_count;         /* Blocks count */
	UInt32   s_r_blocks_count;       /* Reserved blocks count */
	UInt32   s_free_blocks_count;    /* Free blocks count */
	UInt32   s_free_inodes_count;    /* Free inodes count */
	UInt32   s_first_data_block;     /* First Data Block */
	UInt32   s_log_block_size;       /* Block size */
	Int32    s_log_frag_size;        /* Fragment size */
	UInt32   s_blocks_per_group;     /* # Blocks per group */
	UInt32   s_frags_per_group;      /* # Fragments per group */
	UInt32   s_inodes_per_group;     /* # Inodes per group */
	UInt32   s_mtime;                /* Mount time */
	UInt32   s_wtime;                /* Write time */
	UInt16   s_mnt_count;            /* Mount count */
	Int16	 s_max_mnt_count;        /* Maximal mount count */
	UInt16   s_magic;                /* Magic signature */
	UInt16   s_state;                /* File system state */
	UInt16   s_errors;               /* Behaviour when detecting errors */
	UInt16   s_pad;
	UInt32   s_lastcheck;            /* time of last check */
	UInt32   s_checkinterval;        /* max. time between checks */
	UInt32   s_creator_os;           /* OS */
	UInt32   s_rev_level;            /* Revision level */
	UInt16   s_def_resuid;           /* Default uid for reserved blocks */
	UInt16   s_def_resgid;           /* Default gid for reserved blocks */
	UInt32   s_reserved[256*2+235];        /* Padding to the end of the block */
} Ext2SuperBlock;

//typedef struct
//{
//	UInt32 s_inodes_count; //����� ����� inode � �������� �������;
//	UInt32 s_blocks_count; //����� ����� ������ � �������� �������;
//	UInt32 s_free_blocks_count; //���������� ��������� ������;
//	UInt32 s_free_inodes_count; //���������� ��������� inode;
//	UInt32 s_first_data_block; //����� ������� ����� ������ (����� �����, � ������� ��������� ���������);
//	UInt32 s_log_block_size; //��� �������� ������������ ��� ���������� ������� �����. ������ ����� ������������ �� �������: block size = 1024 << s_log_block_size;
//	UInt32 s_blocks_per_group; //���������� ������ � ������;
//	UInt32 s_inodes_per_group; //���������� inode � ������;
//	UInt16 s_magic; //������������� �������� ������� ext2 (��������� 0xEF53);
//	UInt16 s_inode_size; //������ ��������������� ���� (inode);
//	UInt32 s_first_ino; //����� ������� �������������������� inode.
//} Ext2SuperBlock;


const UInt16 INODE_TYPE_SYMBOL_LINK = 0xA000; //������������� ������;
const UInt16 INODE_TYPE_FILE = 0x8000; //������� ����;
const UInt16 INODE_TYPE_DEV = 0x6000; //���� �������� ����������;
const UInt16 INODE_TYPE_DIRECTORY = 0x4000; //�������;
const UInt16 INODE_TYPE_CHAR_DEV = 0x2000; //���� ����������� ����������;
const UInt16 INODE_TYPE_FIFO = 0x1000; //����� FIFO.


typedef struct
{
	UInt16 i_mode; //��� ����� � ����� ������� � ����. ��� ����� ���������� ���� 12-15 ����� ����: 
	UInt32 i_size; //������ � ������;
	UInt32 i_atime; //����� ���������� ������� � �����;
	UInt32 i_ctime; //����� �������� �����;
	UInt32 i_mtime; //����� ��������� �����������;
	UInt32 i_blocks; //���������� ������, ���������� ������;
	UInt32 *i_block; //������ �������������� ������ (������� ��� ��������� ������).
} Ext2Inode;


typedef struct 
{
        UInt32   bg_block_bitmap;        /* Blocks bitmap block */
        UInt32   bg_inode_bitmap;        /* Inodes bitmap block */
        UInt32   bg_inode_table;         /* Inodes table block */
        UInt16   bg_free_blocks_count;   /* Free blocks count */
        UInt16   bg_free_inodes_count;   /* Free inodes count */
        UInt16   bg_used_dirs_count;     /* Directories count */
        UInt16   bg_pad;
        UInt32   bg_reserved[3];
}Ext2GroupDescriptorTable;