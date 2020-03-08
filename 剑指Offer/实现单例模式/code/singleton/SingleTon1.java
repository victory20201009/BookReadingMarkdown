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
		if(instance==null){
			synchronized(SingleTon1.class){
				if(instance==null){
					instance = new SingleTon1();
				}
			}
		}
		return instance;
	}
}