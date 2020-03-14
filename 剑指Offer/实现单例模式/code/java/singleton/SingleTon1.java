package singleton;

public final class SingleTon1{
	
	private static SingleTon1 instance = null;
	
	
	private SingleTon1(){}
	
	/*
	public static SingleTon1 getInstance(){
		if(instance==null){
			instance = new SingleTon1();
		}
		return instance;
	}
	
	public static SingleTon1 getInstance(){
		synchronized(SingleTon1.class){
			if(instance==null){
				instance = new SingleTon1();
			}
		}
		return instance;
	}*/
	
	public static SingleTon1 getInstance(){
		if(instance==null){//这个判读是为了当instance不是null时，直接返回，而不是获取锁，提高效率，每次获取锁是不必要的
			synchronized(SingleTon1.class){
				if(instance==null){
					instance = new SingleTon1();
				}
			}
		}
		return instance;
	}
}