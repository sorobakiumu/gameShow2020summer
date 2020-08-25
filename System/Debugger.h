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
    /// ������ 
    /// </summary> 
    /// <returns>Debugger�C���X�^���X</returns> 
    static Debugger& Instance();

    /// <summary> 
    /// ���f�o�b�O���[�h���ǂ��� 
    /// </summary> 
    /// <returns>true�F�f�o�b�O���[�h</returns> 
    bool IsDebugMode()const;

    /// <summary> 
    /// ���t���[���Ă΂�����ϐ����X�V���Ă��� 
    /// </summary> 
    void Update();

    /// <summary> 
    /// �p�t�H�[�}���X�J�E���^��\������ 
    /// </summary> 
    void DisplayPerformance();
};

