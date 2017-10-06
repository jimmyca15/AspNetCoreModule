#pragma once
class INPROCESS_STORED_CONTEXT : public IHttpStoredContext
{
public:
    INPROCESS_STORED_CONTEXT(
        IHttpContext* pHttpContext,
        PVOID pvManagedContext
    );
    ~INPROCESS_STORED_CONTEXT();

    virtual
    VOID
    CleanupStoredContext(
        VOID
    )
    {
        delete this;
    }

    virtual
    VOID
    OnClientDisconnected(
        VOID
    )
    {
    }

    virtual
        VOID
        OnListenerEvicted()
    {
        // Do nothing - at the end of the request the managed pipeline executor will explicitly release
        // any GCHandles that were created for evicted listeners.
    }

    PVOID QueryManagedHttpContext();
    IHttpContext* QueryHttpContext();

private:
    PVOID m_pManagedHttpContext;
    IHttpContext* m_pHttpContext;
};

