#ifndef BOOK_STORE_HPP
#define BOOK_STORE_HPP

/**
 * You don't need to edit this file, although you can
 * 	if you wish to add helper methods.
 */

//
#include "DoublyLinkedList.hpp"
#include "Book.hpp"


//
namespace CPSC131
{
	//
	namespace BookStore
	{
		//
		class BookStore
		{
			public:
				
				//
				BookStore();
				
				//
				void adjustAccountBalance(int adjustment);
				int getAccountBalance() const;
				
				//
				Book& getBook(std::string isbn) const;
				DoublyLinkedList::DoublyLinkedList<Book>::Iterator findBook(std::string isbn) const;
				bool bookExists(std::string isbn) const;
				size_t getBookStockAvailable(std::string isbn) const;
				
				//
				void purchaseInventory(const Book& book);
				void purchaseInventory(
					std::string title, std::string author, std::string isbn,
					size_t price_cents,
					size_t unit_count
				);
				
				//
				void sellToCustomer(std::string isbn, size_t price_cents, size_t quantity);
				void sellToCustomer(Book& book, size_t price_cents, size_t quantity);
				
				//
				void printInventory() const;
				
			private:
				
				//
				::CPSC131::DoublyLinkedList::DoublyLinkedList<Book> bookList;
				
				int account_balance_ = 0;
		};
	}
}


#endif
