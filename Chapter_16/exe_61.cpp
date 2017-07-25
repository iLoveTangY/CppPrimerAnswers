//����ָ����make_shared������ʵ��
template <typename T, typename... Args>
shared_ptr<T> make_shared(Args&&... args)
{
	return shared_ptr<T>(new T(std::forward<Args>(args)...));
}