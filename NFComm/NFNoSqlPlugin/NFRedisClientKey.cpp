//
// Author: LUSHENG HUANG Created on 17/11/17.
//
#include "NFRedisClient.h"

NFRedisResult* NFRedisClient::DEL(const std::string &key)
{
    m_pRedisResult->Reset();

    NFRedisCommand cmd(GET_NAME(DEL));
    cmd << key;

    std::string msg = cmd.Serialize();
	m_pRedisResult->SetCommand(msg);

    int nRet = m_pRedisClientSocket->Write(msg.data(), msg.length());
    if (nRet != 0)
    {
        return m_pRedisResult;
    }

    GetStatusReply();


    return m_pRedisResult;
}

NFRedisResult* NFRedisClient::EXISTS(const std::string &key)
{
    m_pRedisResult->Reset();

    NFRedisCommand cmd(GET_NAME(EXISTS));
    cmd << key;

    std::string msg = cmd.Serialize();
	m_pRedisResult->SetCommand(msg);

    int nRet = m_pRedisClientSocket->Write(msg.data(), msg.length());
    if (nRet != 0)
    {
        return m_pRedisResult;
    }

    GetStatusReply();


    return m_pRedisResult;
}

NFRedisResult *NFRedisClient::EXPIRE(const std::string &key, const unsigned int secs)
{
    m_pRedisResult->Reset();

    NFRedisCommand cmd(GET_NAME(EXPIRE));
    cmd << key;
    cmd << secs;

    std::string msg = cmd.Serialize();
	m_pRedisResult->SetCommand(msg);

    int nRet = m_pRedisClientSocket->Write(msg.data(), msg.length());
    if (nRet != 0)
    {
        return m_pRedisResult;
    }

    GetStatusReply();


    return m_pRedisResult;
}

NFRedisResult *NFRedisClient::EXPIREAT(const std::string &key, const int64_t unixTime)
{
    m_pRedisResult->Reset();

    NFRedisCommand cmd(GET_NAME(EXPIREAT));
    cmd << key;
    cmd << unixTime;

    std::string msg = cmd.Serialize();
	m_pRedisResult->SetCommand(msg);

    int nRet = m_pRedisClientSocket->Write(msg.data(), msg.length());
    if (nRet != 0)
    {
        return m_pRedisResult;
    }

    GetStatusReply();


    return m_pRedisResult;
}

NFRedisResult *NFRedisClient::PERSIST(const std::string &key)
{
    m_pRedisResult->Reset();

    NFRedisCommand cmd(GET_NAME(PERSIST));
    cmd << key;

    std::string msg = cmd.Serialize();
	m_pRedisResult->SetCommand(msg);

    int nRet = m_pRedisClientSocket->Write(msg.data(), msg.length());
    if (nRet != 0)
    {
        return m_pRedisResult;
    }

    GetStatusReply();


    return m_pRedisResult;
}

NFRedisResult *NFRedisClient::TTL(const std::string &key)
{
    m_pRedisResult->Reset();

    NFRedisCommand cmd(GET_NAME(TTL));
    cmd << key;

    std::string msg = cmd.Serialize();
	m_pRedisResult->SetCommand(msg);

    int nRet = m_pRedisClientSocket->Write(msg.data(), msg.length());
    if (nRet != 0)
    {
        return m_pRedisResult;
    }

    GetStatusReply();


    return m_pRedisResult;
}

NFRedisResult *NFRedisClient::TYPE(const std::string &key)
{
    m_pRedisResult->Reset();

    NFRedisCommand cmd(GET_NAME(TYPE));
    cmd << key;

    std::string msg = cmd.Serialize();
	m_pRedisResult->SetCommand(msg);

    int nRet = m_pRedisClientSocket->Write(msg.data(), msg.length());
    if (nRet != 0)
    {
        return m_pRedisResult;
    }

    GetStatusReply();


    return m_pRedisResult;
}