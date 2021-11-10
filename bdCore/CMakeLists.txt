add_library(bdCore STATIC
    bdContainers/bdArray.h
    bdContainers/bdBitBuffer.h
    bdContainers/bdBitBufferTypes.h
    bdContainers/bdByteBuffer.h
    bdContainers/bdCircularBuffer.h
    bdContainers/bdFastArray.h
    bdContainers/bdHashmap.h
    bdContainers/bdLinkedList.h
    bdContainers/bdNonce.h
    bdContainers/bdPriorityHeap.h
    bdContainers/bdPriorityQueue.h
    bdContainers/bdQueue.h
    bdContainers/bdRedBlacktree.h
    bdContainers/bdSequenceNumber.h
    bdContainers/bdSequenceNumberStore.h
    bdContainers/bdSet.h
    bdContainers/bdSingleton.h

    bdCrypto/bdCryptoConfig.h
    bdCrypto/bdCryptoUtils.h
    bdCrypto/bdCypher.h
    bdCrypto/bdCypher3DES.h
    bdCrypto/bdEECKey.h
    bdCrypto/bdHash.h
    bdCrypto/bdHashMD5.h
    bdCrypto/bdRSAKey.h

    bdMemory/bdDefaultMemory.h
    bdMemory/bdMallocMemory-std.h
    bdMemory/bdMallocMemory.h
    bdMemory/bdMemory-std.h
    bdMemory/bdMemory.h

    bdReference/bdReferencable.h
    bdReference/bdReference.h
    
    bdSocket/bdAddr.h
    bdSocket/bdCommonAddr.h
    bdSocket/bdCommonAddrInfo.h
    bdSocket/bdDefaultSocket.h
    bdSocket/bdEndpoint.h
    bdSocket/bdINetAddr.h
    bdSocket/bdPort.h
    bdSocket/bdSecurityID.h
    bdSocket/bdSecurityInfo.h
    bdSocket/bdSecurityKey.h
    bdSocket/bdSocket.h
    bdSocket/bdSocketConfig.h
    bdSocket/bdStreamSocket.h

    bdString/bdString.h

    bdThread/bdMutex.h
    bdThread/bdRunnable.h
    bdThread/bdSemaphore.h
    bdThread/bdThread.h

    bdTiming/bdStopwatch.h
    bdTiming/bdStopwatch.cpp

    bdUtilities/bdBase64.h
    bdUtilities/bdBitOperations.h
    bdUtilities/bdBytePacker.h
    bdUtilities/bdComparisonFunctors.h
    bdUtilities/bdFactory.h
    bdUtilities/bdRandom.h
    bdUtilities/bdTrulyRandom.h

    bdCore.h
)

create_target_directory_groups(bdCore)

target_compile_options(bdCore PUBLIC
                                        #/Zi
										/arch:SSE2
										/fp:fast           # fast floating point
										/errorreport:none
                                        /Od
										#/Ob2
										/Oi               # intrinsic functions
										/Oy               # supress frame pointer
										/Ot               # use faster code
										/GT               # tls
										#/W4
										/Gy              # function level linking
										/GF              # string pooling
										#/WX
                                        /utf-8
        )

target_compile_definitions(bdCore PUBLIC
    "_DEBUG"
    "WIN32;"
    "_WINDOWS;"
    "_CRT_SECURE_NO_WARNINGS;"
    "NDEBUG;"
    "DEVELOPMENT;"
)

target_link_options(bdCore PUBLIC
    /NOLOGO;
    /STACK:8388608;
    /DEBUG
    #/MACHINE:X86;
    /SUBSYSTEM:WINDOWS;
    /DYNAMICBASE:NO;
    /INCREMENTAL:NO)