#include "precomp.hxx"
INPROCESS_STORED_CONTEXT::INPROCESS_STORED_CONTEXT(
    IHttpContext* pHttpContext,
    PVOID pMangedHttpContext
)
{
    m_pManagedHttpContext = pMangedHttpContext;
    m_pHttpContext = pHttpContext;
}

INPROCESS_STORED_CONTEXT::~INPROCESS_STORED_CONTEXT()
{
}

PVOID
INPROCESS_STORED_CONTEXT::QueryManagedHttpContext(
)
{
    return m_pManagedHttpContext;
}

IHttpContext*
INPROCESS_STORED_CONTEXT::QueryHttpContext(
)
{
    return m_pHttpContext;
}