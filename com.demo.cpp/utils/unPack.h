#pragma once

class UnPack
{
	private:
		BYTES  m_bin;
		INT32  location = 0;

	public:
		UnPack() {}
		UnPack(BYTES bin) : m_bin(bin) {}
		UnPack(string bin)
		{
			m_bin.assign(bin.begin(), bin.end());
		}
		/* ��� */
		void Empty();
		/* ȡ�������� */
		BYTES & GetAll();
		/* ȡ�ֽڼ� */
		BYTES GetBin(INT32);
		/* ȡ�ֽ� */
		BYTE GetByte();
		/* ȡ���� */
		INT32 GetInt();
		/* ȡ������ */
		INT64 GetLong();
		/* ȡ������ */
		INT16 GetShort();
		/* ȡ�ı� */
		string GetLenStr();
		/* ȡ? */
		BYTES GetLenBin();
		/* ȡ���� */
		BYTES GetToken();
		/* ȡ���� */
		INT32 Len();
		/* ������ */
		void SetData(BYTES);
};