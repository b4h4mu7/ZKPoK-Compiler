#ifndef HWSWTARGETMACHINE_H
#define HWSWTARGETMACHINE_H

#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetData.h"

namespace llvm {

  class HWSWTargetMachine : public TargetMachine {
  public:
    HWSWTargetMachine(const Target &T, StringRef TT,
		       StringRef CPU, StringRef FS,
		       Reloc::Model RM, CodeModel::Model CM) 
      : TargetMachine(T, TT, CPU, FS) {}

    virtual bool addPassesToEmitFile(PassManagerBase &PM,
				     formatted_raw_ostream &Out,
				     CodeGenFileType FileType,
				     CodeGenOpt::Level OptLevel,
				     bool DisableVerify);

    virtual const TargetData *getTargetData() const { return 0; }
  };
}

#endif