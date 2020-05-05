//
// Created by Le Xu on 2020-05-05.
//
#include <nvToolsExt.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <string>
//https://github.com/tlorach/nvFX/blob/master/NSight/nvToolsExt.h
struct nvtxTagger{
private:
	std::string tag_;
public:
	nvtxTagger(std::string tag_name):tag_(tag_name){
		nvtxRangePushA(tag_);
	}
	~nvtxTagger(){
		nvtxRangePop();
	}
};
