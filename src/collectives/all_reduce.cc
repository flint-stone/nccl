/*************************************************************************
 * Copyright (c) 2015-2019, NVIDIA CORPORATION. All rights reserved.
 *
 * See LICENSE.txt for license information
 ************************************************************************/

#include "enqueue.h"
#include "nvtxTagger.h"
#include "debug.h"

NCCL_API(ncclResult_t, ncclAllReduce, const void* sendbuff, void* recvbuff, size_t count,
    ncclDataType_t datatype, ncclRedOp_t op, ncclComm* comm, cudaStream_t stream);
ncclResult_t ncclAllReduce(const void* sendbuff, void* recvbuff, size_t count,
    ncclDataType_t datatype, ncclRedOp_t op, ncclComm* comm, cudaStream_t stream) {
	INFO(NCCL_COLL, "create dummy tagger: nccl: AllReduce rank %d, nRanks %d, node %d, nNodes %d, localRanks %d, opCount %d, lastOpCount %d, nChannels %d, p2pnChannels %d, p2pnChannelsPerPeer %d "
     comm->rank, comm->nRanks, comm->node, comm->nNodes, comm->localRanks, comm->opCount, comm->lastOpCount, comm->nChannels, comm->p2pnChannels, comm->p2pnChannelsPerPeer );
	nvtxTagger dummyTagger = nvtxTagger("nccl: AllReduce");
  struct ncclInfo info = { ncclCollAllReduce, "AllReduce",
    sendbuff, recvbuff, count, datatype, op, 0, comm, stream, /* Args */
    ALLREDUCE_CHUNKSTEPS, ALLREDUCE_SLICESTEPS };
  return ncclEnqueueCheck(&info);
}
