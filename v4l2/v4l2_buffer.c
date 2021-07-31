struct v4l2_buffer

{

u32 index; //buffer 序号

enum v4l2_buf_type type; //buffer 类型

u32 byteused; //buffer 中已使用的字节数

u32 flags; // 区分是MMAP 还是USERPTR

enum v4l2_field field;

struct timeval timestamp; // 获取第一个字节时的系统时间

struct v4l2_timecode timecode;

u32 sequence; // 队列中的序号

enum v4l2_memory memory; //IO 方式，被应用程序设置

union m

{

u32 offset; // 缓冲帧地址，只对MMAP 有效

unsigned long userptr;

};

u32 length; // 缓冲帧长度

u32 input;

u32 reserved;

};
