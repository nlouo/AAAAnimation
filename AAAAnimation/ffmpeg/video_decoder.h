﻿#pragma once
#include <string>
#include "stream_wrapper.h"

extern "C" {
#include <libavformat/avformat.h>
}

class VideoDecoder
{
public:
	VideoDecoder(std::string video_path);
	~VideoDecoder();
	AVFrame* next_frame();
	int get_video_width();
	int get_video_height();
	AVRational get_video_timebase();
private:
	AVFormatContext* format_context;
	StreamWrapper video;
	StreamWrapper audio;
	AVPacket* temp_packet;
	AVFrame* current_frame;
};

