//
// Author: LUSHENG HUANG Created on 17/11/17.
//

#include "NFRedisClient.h"

NFRedisResult *NFRedisClient::LINDEX(const std::string &key, const int index) 
{
	m_pRedisResult->Reset();

	NFRedisCommand cmd(GET_NAME(LINDEX));
	cmd << key;
	cmd << index;

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

NFRedisResult *NFRedisClient::LLEN(const std::string &key)
{
	m_pRedisResult->Reset();

	NFRedisCommand cmd(GET_NAME(LLEN));
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

NFRedisResult *NFRedisClient::LPOP(const std::string &key)
{
	m_pRedisResult->Reset();

	NFRedisCommand cmd(GET_NAME(LPOP));
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

NFRedisResult *NFRedisClient::LPUSH(const std::string &key, const std::string &value)
{
	m_pRedisResult->Reset();

	NFRedisCommand cmd(GET_NAME(LPUSH));
	cmd << key;
	cmd << value;

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

NFRedisResult *NFRedisClient::LPUSHX(const std::string &key, const std::string &value) 
{
	m_pRedisResult->Reset();

	NFRedisCommand cmd(GET_NAME(LPUSHX));
	cmd << key;
	cmd << value;

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

NFRedisResult *NFRedisClient::LRANGE(const std::string &key, const int start, const int end, string_vector &values) 
{

	m_pRedisResult->Reset();
	if (end - start <= 0)
	{
		return m_pRedisResult;
	}

	NFRedisCommand cmd(GET_NAME(LRANGE));
	cmd << key;
	cmd << start;
	cmd << end;

	std::string msg = cmd.Serialize();
	m_pRedisResult->SetCommand(msg);

	int nRet = m_pRedisClientSocket->Write(msg.data(), msg.length());
	if (nRet != 0)
	{
		return m_pRedisResult;
	}

	GetArrayReply();

	const std::vector<NFRedisResult> xVector = m_pRedisResult->GetRespArray();
	if ((end - start + 1) == xVector.size())
	{
		for (int i = 0; i < xVector.size(); ++i)
		{
			values.push_back(xVector[i].GetRespString());
		}
	}

	return m_pRedisResult;
}

NFRedisResult *NFRedisClient::LSET(const std::string &key, const int index, const std::string &value)
{
	m_pRedisResult->Reset();

	NFRedisCommand cmd(GET_NAME(LSET));
	cmd << key;
	cmd << index;
	cmd << value;

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

NFRedisResult *NFRedisClient::RPOP(const std::string &key)
{
	m_pRedisResult->Reset();

	NFRedisCommand cmd(GET_NAME(RPOP));
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

NFRedisResult *NFRedisClient::RPUSH(const std::string &key, const std::string &value) 
{
	m_pRedisResult->Reset();

	NFRedisCommand cmd(GET_NAME(RPUSH));
	cmd << key;
	cmd << value;

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

NFRedisResult *NFRedisClient::RPUSHX(const std::string &key, const std::string &value)
{
	m_pRedisResult->Reset();

	NFRedisCommand cmd(GET_NAME(RPUSHX));
	cmd << key;
	cmd << value;

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
