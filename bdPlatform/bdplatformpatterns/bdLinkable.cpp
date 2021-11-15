#include "bdLinkable.h"

bdLinkable::bdLinkable()
{
	m_previous = 0;
	m_next = 0;
	m_headPtr = 0;
}

bdLinkable::~bdLinkable()
{
	unlink();
}

void bdLinkable::link(bdLinkable** head)
{
	unlink();
	if (head)
	{
		bdLinkable* h = *head;
		m_previous = 0;
		m_next = h;
		if (h)
		{
			h->m_previous = this;
		}
		*head = this;
		m_headPtr = head;
	}
}

void bdLinkable::unlink()
{
	if (m_previous)
	{
		m_previous->m_next = m_next;
	}
	if (m_next)
	{
		m_next->m_previous = m_previous;
	}
	if (m_headPtr && *m_headPtr == this)
	{
		*m_headPtr = m_next;
	}
	m_previous = 0;
	m_next = 0;
	m_headPtr = 0;
}

bdLinkable* bdLinkable::getNext()
{
	return m_next;
}

bool bdLinkable::find(bdLinkable* list, bdLinkable* link)
{
	bool found = false;

	while (!found && list)
	{
		found = list == link;
		list = list->getNext();
	}
	return found;
}

