#pragma once
#include<vector>
using namespace std;
 
namespace DT {
	template <typename T>
	class IDataRepository {
	public:
		virtual vector<T> Get() const = 0;
		virtual void Add(T item)=0;
		virtual void Remove(T item)=0;
	
	};
}
