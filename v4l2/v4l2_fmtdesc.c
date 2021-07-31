struct v4l2_fmtdesc

{

u32 index; // 要查询的格式序号，应用程序设置

enum v4l2_buf_type type; // 帧类型，应用程序设置

u32 flags; // 是否为压缩格式

u8 description[32]; // 格式名称

u32 pixelformat; // 格式

u32 reserved[4]; // 保留

};
