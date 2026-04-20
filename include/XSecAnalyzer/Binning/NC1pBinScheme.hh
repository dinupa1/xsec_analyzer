#pragma once

#include "XSecAnalyzer/Binning/BinSchemeBase.hh"

class NC1pBinScheme : public BinSchemeBase {

  public:

    NC1pBinScheme();
    virtual void DefineBlocks() override;
};
