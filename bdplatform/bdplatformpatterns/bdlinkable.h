#pragma once

class bdLinkable
{
public:
	bdLinkable* m_previous;
	bdLinkable* m_next;
	bdLinkable** m_headPtr;

	bdLinkable();
	virtual ~bdLinkable();
	void link(bdLinkable** head);
	void unlink();
	bdLinkable* getNext();
	static bool find(bdLinkable* list, bdLinkable* link);
};