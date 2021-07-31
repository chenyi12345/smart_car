struct v4l2_requestbuffers

{

u32 count; // 缓冲区内缓冲帧的数目

enum v4l2_buf_type type; // 缓冲帧数据格式

enum v4l2_memory memory; // 区别是内存映射还是用户指针方式

u32 reserved[2];

:x
ls
