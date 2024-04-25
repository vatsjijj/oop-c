#ifndef CLASS_H
#define CLASS_H

// Class syntax macros.
#define CALL(obj, name) obj.vt.name(&obj)
#define METHOD_PTR(obj, name) obj.vt.name
#define MEMBER(name) this->name
#define THIS(name) this.name
#define EXTENDS(class) class base ## class
#define NEW(class) new ## class
#define METHOD(name) this->vt.name
#define CAST(obj, class) obj.base ## class
#define OVERLOAD(obj, method, newMethod) obj.vt.method = newMethod

// Definition helper macros.
#define FPTR_T(ret, name, args) ret (*name)args
#define CLASS_T(name) struct name name
#define VTABLE_T(name) struct name ## VTable name ## VTable
#define CLASS(name) CLASS_T(name); typedef VTABLE_T(name)
#define VTABLE(name) name ## VTable vt
#define DEF_METHOD(ret, name, class) ret name ## class ## Method

// Constructor helper macros.
#define INIT(class) class ## VTable vt; class this
#define CONSTRUCTOR(class) class new ## class
#define OL_CONSTRUCTOR(class, name) class new ## name

#endif