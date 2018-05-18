#include "stdafx.h"
#include "XID.h"
#include <Interpret/InterpretProp2.h>

XID::XID()
{
	m_NamespaceGuid = { 0 };
	m_cbLocalId = 0;
}

void XID::Parse()
{
	m_NamespaceGuid = m_Parser.Get<GUID>();
	m_cbLocalId = m_Parser.RemainingBytes();
	m_LocalID = m_Parser.GetBYTES(m_cbLocalId, m_cbLocalId);
}

_Check_return_ std::wstring XID::ToStringInternal()
{
	return strings::formatmessage(IDS_XID,
		GUIDToString(&m_NamespaceGuid).c_str(),
		strings::BinToHexString(m_LocalID, true).c_str());
}