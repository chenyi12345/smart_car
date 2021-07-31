struct v4l2_format

{

enum v4l2_buf_type type; // 帧类型，应用程序设置

union fmt

{

struct v4l2_pix_format pix; // 视频设备使用

struct v4l2_window win;

struct v4l2_vbi_format vbi;

struct v4l2_sliced_vbi_format sliced;

u8 raw_data[200];

};

};

struct v4l2_pix_format

{

u32 width; // 帧宽，单位像素

u32 height; // 帧高，单位像素

u32 pixelformat; // 帧格式

enum v4l2_field field;

u32 bytesperline;

u32 sizeimage;

enum v4l2_colorspace colorspace;

u32 priv;

};
