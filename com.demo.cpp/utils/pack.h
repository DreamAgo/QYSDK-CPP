#pragma once

class Pack
{
	private:
		BYTES m_bin;

	public:
		/* ��� */
		void Empty();
		/* ȡȫ������ */
		BYTES & GetAll();
		/* ȡ���� */
		size_t Len();
		/* ���ֽڼ� */
		void SetBin(BYTES);
		/* ���ֽ� */
		void SetByte(BYTE);
		/* �������� */
		void SetData(BYTES);
		/* ������ */
		void SetInt(INT32);
		/* �ö����� */
		void SetShort(INT16);
		/* �ó����� */
		void SetLong(INT64);
		/* ���ı� */
		void SetStr(string);
		/* ��? */
		void SetLenStr(string);
		/* ������ */
		void SetToken(BYTES);
};