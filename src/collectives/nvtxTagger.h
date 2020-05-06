//
// Created by Le Xu on 2020-05-05.
//
#include <nvToolsExt.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <string>
#include "debug.h"
//https://github.com/tlorach/nvFX/blob/master/NSight/nvToolsExt.h
struct nvtxTagger{
private:
	std::string tag_;
public:
	nvtxTagger(std::string tag_name):tag_(tag_name){
		WARN("nvtxTagger: enter %s", tag_.c_str());
		nvtxRangePushA(tag_.c_str());
	}
	~nvtxTagger(){
		nvtxRangePop();
		WARN("nvtxTagger: exit %s", tag_.c_str());
	}
};
