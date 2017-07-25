//智能指针中make_shared函数的实现
template <typename T, typename... Args>
shared_ptr<T> make_shared(Args&&... args)
{
	return shared_ptr<T>(new T(std::forward<Args>(args)...));
}