#pragma once
#include <forward_list>

namespace GameCore
{
	template<class T>
	class List
	{
	public:
		List();

		/// <summary>
		/// Adds something to the front of this list.
		/// </summary>
		/// <returns>Nothing now (Will return whether or not the item was successfully added).</returns>
		bool pushFront(T object);
		/// <summary>
		/// Removes something from the list.
		/// </summary>
		/// <returns>Nothing now (Will return whether or not the item was successfully removed).</returns>
		bool remove(T object);
		/// <summary>
		/// Returns an iterator that starts at the beginning of the list.
		/// </summary>
		auto begin();
		/// <summary>
		/// Returns an iterator that starts at the end of the list.
		/// </summary>
		auto end();

	private:
		std::forward_list<T> m_list;
	};

	template<class T>
	inline List<T>::List()
	{
	}

	template<class T>
	inline bool List<T>::pushFront(T object)
	{
		// Items can be added more thans once...
		// Always returns true...
		m_list.push_front(object);
		return false;
	}

	template<class T>
	inline bool List<T>::remove(T object)
	{
		// Always returns true for now...
		m_list.remove(object);
		return true;
	}
	template<class T>
	inline auto List<T>::begin()
	{
		return m_list.begin();
	}
	template<class T>
	inline auto List<T>::end()
	{
		return m_list.end();
	}
}


