// Copyright (c) 2013 Shotgun Software Inc.

#ifndef ProcessManager_h__
#define ProcessManager_h__

#include <vector>
#include <string>
#include <boost/asio.hpp>
#include <boost/function.hpp>
#include <boost/noncopyable.hpp>
#include "BrowserHost.h"

typedef boost::function<void (const FB::VariantList&)> PathCallback;
typedef boost::function<void (int, const std::string&, const std::string&)> ExecuteTankCallback;

namespace FB { class PluginWindow; }

class ProcessManager
{
public:
    static ProcessManager* get();
    virtual void Open(const FB::BrowserHostPtr& host, const std::string &path) = 0;
    void ExecuteTankCommand(
        const FB::BrowserHostPtr& host,
        const std::string &pipelineConfigPath,
        const std::string &command,
        const std::vector<std::string> &args,
        const ExecuteTankCallback &cb);

protected:
    ProcessManager() {}
    virtual ~ProcessManager() {}
};

#endif // ProcessManager_h__