////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
////////////////////
#ifndef __IRenderer_h__
#define __IRenderer_h__
////////////////////////////////////////////////////////////////////////////////
class IRenderer 
{
public:
  virtual void Render( const std::string & str ) = 0;

  //Template functions that can render up to 3 parameters
  template<typename T1>
  void Render(T1 & par1)
  {
    std::cout << par1;
  }

  template<typename T1, typename T2>
  void Render(T1 & par1, T2 & par2)
  {
	  std::cout << par1 << par2;
  }

  template<typename T1, typename T2, typename T3>
  void Render(T1 & par1, T2 & par2, T3 & par3)
  {
	 std::cout << par1 << par2 << par3;
  }

};
////////////////////////////////////////////////////////////////////////////////
#endif
