#pragma once
class Debugger
{
private:
    Debugger() = default;
    Debugger(const Debugger&) = delete;
    void operator =(const Debugger&) = delete;
    bool DebugDisp_=false;
public:
    /// <summary> 
    /// いつもの 
    /// </summary> 
    /// <returns>Debuggerインスタンス</returns> 
    static Debugger& Instance();

    /// <summary> 
    /// 今デバッグモードかどうか 
    /// </summary> 
    /// <returns>true：デバッグモード</returns> 
    bool IsDebugMode()const;

    /// <summary> 
    /// 毎フレーム呼ばれ内部変数を更新している 
    /// </summary> 
    void Update();

    /// <summary> 
    /// パフォーマンスカウンタを表示する 
    /// </summary> 
    void DisplayPerformance();
};

