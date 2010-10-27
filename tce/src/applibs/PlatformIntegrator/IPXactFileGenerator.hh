/*
    Copyright (c) 2002-2010 Tampere University of Technology.

    This file is part of TTA-Based Codesign Environment (TCE).

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
    DEALINGS IN THE SOFTWARE.
 */
/**
 * @file IPXactFileGenerator.hh
 *
 * Declaration of IPXactFileGenerator class.
 *
 * @author Otto Esko 2010 (otto.esko-no.spam-tut.fi)
 * @note rating: red
 */
#ifndef TTA_IP_XACT_FILE_GENERATOR_HH
#define TTA_IP_XACT_FILE_GENERATOR_HH

#include <string>
#include <vector>
#include "ProjectFileGenerator.hh"
#include "IPXactModel.hh"

class PlatformIntegrator;
class IPXactSerializer;

class IPXactFileGenerator : public ProjectFileGenerator {
public:

    IPXactFileGenerator(std::string toplevelEntity,
                        const PlatformIntegrator* integrator);

    virtual ~IPXactFileGenerator();

    virtual void writeProjectFiles();

private:

    void addBusInterfaces(IPXactModel* model);

    bool searchInterface(
        const SignalMappingList& search,
        SignalMappingList& found) const;

    std::string outputFileName() const;

    IPXactSerializer* ipXactWriter_;

    typedef std::map<IPXactModel::IPXactBus, SignalMappingList*> BusMapping;
    BusMapping busInterfaces_;
};
#endif