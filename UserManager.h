﻿#pragma once

#include <memory>
#include "Common.h"
#include "Protocol.h"
#include "utils/noncopyable.h"
#include "network/tcpsession.h"
using qyhnetwork::TcpSessionPtr;

class UserManager;
using UserManagerPtr = std::shared_ptr<UserManager>;

class UserManager :private noncopyable, public std::enable_shared_from_this<UserManager>
{
public:
    static UserManagerPtr getInstance()
	{
        static UserManagerPtr m_inst = UserManagerPtr(new UserManager());
		return m_inst;
	}

    void interLogin(TcpSessionPtr conn, MSG_Request msg);

    void interLogout(TcpSessionPtr conn, MSG_Request msg);

    void interChangePassword(TcpSessionPtr conn, MSG_Request msg);

    void interList(TcpSessionPtr conn, MSG_Request msg);

    void interRemove(TcpSessionPtr conn, MSG_Request msg);

    void interAdd(TcpSessionPtr conn, MSG_Request msg);

    void interModify(TcpSessionPtr conn, MSG_Request msg);

	virtual ~UserManager();
private:
	UserManager();
};

