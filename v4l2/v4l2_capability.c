struct v4l2_capability

{

u8 driver[16]; // 驱动名字

u8 card[32]; // 设备名字

u8 bus_info[32]; // 设备在系统中的位置

u32 version; // 驱动版本号

u32 capabilities; // 设备支持的操作

u32 reserved[4]; // 保留字段

};
